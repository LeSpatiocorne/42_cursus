import random, os

items_100 = list(range(0, 100))
items_500 = list(range(0, 500))
random.shuffle(items_100)
random.shuffle(items_500)

os.system("rm -f push_swap_100 push_swap_500")
os.system("touch push_swap_100 push_swap_500")

with open('push_swap_100', 'w') as file:
    for number in items_100:
        file.write(f"{number}\n")

with open('push_swap_500', 'w') as file:
    for number in items_500:
        file.write(f"{number}\n")
