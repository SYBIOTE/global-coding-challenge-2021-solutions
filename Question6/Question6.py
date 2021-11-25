#!/bin/python3

import os
import sys



def theHackathon(n, m, a, b, f, s, t):
    emp_group = {}
    emp_dept ={}
    emp_dept_con = {} 
    max_dep = [f,s,t]
    min_emp = a
    max_emp = b
    test_emp_list = ["a 1","b 2","c 3","d 1","e 2","f 3"]
    test_req_list = ["a b","b c","e d","e f","a f"]
    biggest_group ={}
    max_size  = 0
    for i in range(n):
        name,dep = input().split()
        emp_dept[name] = int(dep)
        emp_group[name] = {name}
        emp_dept_con[name] = [0,0,0]
        emp_dept_con[name][int(dep)-1] = 1

    for i in range(m):
        first_name,second_name = input().split()
        # condition 1:
        if len(emp_group[first_name])+len(emp_group[second_name])>max_emp:
            continue  
        # condition 2:
        c= True
        new_dep = [0,0,0]
        for i in range(3):
            new_dep[i] = emp_dept_con[second_name][i]+emp_dept_con[first_name][i]
            if new_dep[i]>max_dep[i]:
                c = False
                break
        # both conditions passeds
        if c:
            temp = emp_group[first_name]|emp_group[second_name]
            for i in temp:
                emp_group[i] = temp
                emp_dept_con[i] = new_dep
            if len(temp) == max_size:
                biggest_group = biggest_group|temp
            elif len(temp)>max_size:
                biggest_group = temp 
                max_size = len(temp) 
    biggest_group = sorted(biggest_group)
    if max_size < min_emp:
        print("no groups")
    else:
        for i in biggest_group:
            print(i)
    # Participant code here

if __name__ == '__main__':
    #inp = "6 5 2 5 2 2 2"
    inputdata = input().split()

    n = int(inputdata[0])

    m = int(inputdata[1])

    a = int(inputdata[2])

    b = int(inputdata[3])

    f = int(inputdata[4])

    s = int(inputdata[5])

    t = int(inputdata[6])

    theHackathon(n, m, a, b, f, s, t)