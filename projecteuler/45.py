T = {int(i * (i+1) / 2) for i in range(1, 100000)}
P = {int(i * (3*i-1) / 2) for i in range(1, 100000)}
H = {int(i * (2*i-1)) for i in range(1, 100000)}
print(T & P & H)
