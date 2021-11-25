import math
def securitiesBuying(z, security_value):
    z=int(z[0])
    no_of_stocks=0
    best_value = {}
    for day in range(0,len(security_value)):
        best_value[int(security_value[day])] = best_value.get(int(security_value[day]),0)+(day+1)
    key_list = sorted(list(best_value.keys()))
    for day in key_list:
        _sum = day * best_value[day]
        if _sum<z:
            z-=_sum
            no_of_stocks += best_value[day]
        else:
            no_of_stocks += math.floor(z/day)
            break
    return no_of_stocks


def main():
    z= input().split()
    security_value = []
    security_value = input().split()
    no_of_stocks_purchased=securitiesBuying(z,security_value)
    print(no_of_stocks_purchased)



if __name__ == '__main__':
    main()