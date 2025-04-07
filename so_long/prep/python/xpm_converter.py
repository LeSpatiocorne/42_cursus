from PIL import Image
import sys
import os

# Définir la couleur de transparence comme None pour la MLX
COLOR_KEY = None

def convert_to_xpm(png_file):
    # Construire les chemins complets
    input_path = os.path.join('input', png_file)
    output_filename = png_file.replace('.png', '.xpm')
    output_path = os.path.join('output', output_filename)

    # Vérifier si le fichier d'entrée existe
    if not os.path.exists(input_path):
        print(f"⚠️ Le fichier {input_path} n'existe pas.")
        return

    img = Image.open(input_path).convert("RGBA")
    pixels = img.load()
    width, height = img.size

    # Créer une map des couleurs uniques
    color_map = {}
    # Liste des caractères à éviter
    forbidden_chars = ['"', '\\', '*', '/', ',']
    char_index = 32  # Commence à l'espace ASCII

    for y in range(height):
        for x in range(width):
            r, g, b, a = pixels[x, y]
            if a == 0:
                if COLOR_KEY is None:
                    color = "None"
                else:
                    color = COLOR_KEY + (255,)
            else:
                color = (r, g, b, a)
            if color not in color_map:
                # Trouver le prochain caractère valide
                while chr(char_index) in forbidden_chars:
                    char_index += 1
                color_map[color] = chr(char_index)
                char_index += 1

    # Créer le contenu du fichier XPM
    xpm_content = [
        "/* XPM */",
        "static char *xpm[] = {",
        f"\"{width} {height} {len(color_map)} 1\",",
    ]

    # Ajouter les définitions de couleurs
    for color, char in color_map.items():
        if color == "None":
            xpm_content.append(f"\"{char} c None\",")  # Transparence MLX
        else:
            r, g, b, a = color
            xpm_content.append(f"\"{char} c #{r:02x}{g:02x}{b:02x}\",")

    # Ajouter les lignes de pixels
    for y in range(height):
        line = ""
        for x in range(width):
            r, g, b, a = pixels[x, y]
            if a == 0:
                color = COLOR_KEY + (255,)
            else:
                color = (r, g, b, a)
            line += color_map[color]
        xpm_content.append(f"\"{line}\",")

    xpm_content[-1] = xpm_content[-1].rstrip(",")  # Enlever la dernière virgule
    xpm_content.append("};")

    # Créer le dossier output s'il n'existe pas
    os.makedirs('output', exist_ok=True)
    
    # Écrire le fichier XPM
    with open(output_path, 'w') as f:
        f.write('\n'.join(xpm_content))
    
    print(f"✅ {png_file} converti en {output_path} avec la couleur clé {COLOR_KEY}")

if __name__ == "__main__":
    # Si aucun argument n'est fourni, convertir tous les PNG du dossier input
    if len(sys.argv) < 2:
        if not os.path.exists('input'):
            print("⚠️ Le dossier 'input' n'existe pas.")
            sys.exit(1)
        
        for file in os.listdir('input'):
            if file.lower().endswith('.png'):
                convert_to_xpm(file)
    else:
        # Sinon, convertir les fichiers spécifiés en argument
        for file in sys.argv[1:]:
            if file.lower().endswith('.png'):
                convert_to_xpm(file)
            else:
                print(f"⚠️ {file} n'est pas un fichier PNG valide.")
