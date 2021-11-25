import math
def sol(n):
    if n ==0:
        return 0 
    if n%3 ==0:
        return 2*(n//3)
    else:    
        return 2*(n//3)+1
    

# do not edit below code
def main():
    n=int(input())
    print(sol(n))

if __name__ == '__main__':
    main()