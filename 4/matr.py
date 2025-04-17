from random import randint as r

n=int(input("n: "))
with open("matr.txt", "w") as f:
    f.write(f"{n}\n")
    for _ in range(n):
        f.write("\t".join(list(map(str, [r(-10,10) for _ in range(n)] ))))
        f.write("\n")
