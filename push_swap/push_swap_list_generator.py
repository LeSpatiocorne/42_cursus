import random, os

items_100 = list(range(0, 100))
items_500 = list(range(0, 500))
items_1000 = list(range(0, 1000))
random.shuffle(items_100)
random.shuffle(items_500)
random.shuffle(items_1000)

os.system("rm -f push_swap_100 push_swap_500")
os.system("touch push_swap_100 push_swap_500")
os.system("touch push_swap_1000")

with open('push_swap_100', 'w') as file:
    for number in items_100:
        file.write(f"{number}\n")

with open('push_swap_500', 'w') as file:
    for number in items_500:
        file.write(f"{number}\n")

with open('push_swap_1000', 'w') as file:
    for number in items_1000:
        file.write(f"{number}\n")
