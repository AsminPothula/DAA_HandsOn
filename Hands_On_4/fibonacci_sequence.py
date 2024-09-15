# python implementation of fibonacci sequence
#def fib(n):
#   if n == 0:
#        return 0
#    if n == 1:
#        return 1
#    return fib(n-1) + fib(n-2)


# run and debug with n = 5 
def fib(n):
    print(f"fib({n}) called")
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fib(n-1) + fib(n-2)

test = fib(5)
#calling the fib function with n=5 for testing purposes
print("Fibonacci of 5:", test)



#output explanation:

# fib(5):  
#   fib(4), fib(3)
#   fib(4): 
#       fib(3), fib(2)
#       fib(3):
#           fib(2), fib(1)
#           fib(2):
#               fib(1), fib(0)
#               fib(1):
#                   = 1
#               fib(0):
#                   = 0 
#               => fib(2) = 1 + 0 = 1
#           fib(1):
#               = 1
#           => fib(3) = fib(2) + fib (1) = 1 + 1 = 2
#       fib(2):
#           fib(1), fib(0)
#           fib(1):
#               = 1
#           fib(0):
#               = 0 
#           => fib(2) = 1 + 0 = 1  
#       => fib(4) = fib(3) + fib(2) = 2 + 1 = 3
#   fib(3):
#       fib(2), fib(1)
#       fib(2):
#           fib(1), fib(0)
#           fib(1):
#               = 1
#           fib(0):
#               = 0 
#           => fib(2) = 1 + 0 = 1
#       fib(1):
#           = 1
#       => fib(3) = fib(2) + fib (1) = 1 + 1 = 2
#   => fib(5) = fib(4) + fib(3) = 3 + 2 = 5