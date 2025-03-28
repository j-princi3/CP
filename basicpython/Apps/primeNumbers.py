# Python program to print all primes smaller than or equal to 
# n using Sieve of Eratosthenes 

def SieveOfEratosthenes(n): 	
	# Create a boolean array "prime[0..n]" and initialize 
	# all entries to true. A value in prime[i] will 
	# finally be false if i is Not a prime, else true. 
	prime = [True for i in range(n+1)] 
	p = 2
	while (p * p <= n): 
		
		# If prime[p] is not changed, then it is a prime 
		if (prime[p] == True): 
			
			# Update all multiples of p 
			for i in range(p * p, n+1, p): 
				prime[i] = False
		p += 1
	
	# Print all prime numbers 
	for p in range(2, n+1): 
		if prime[p]: 
			print(p) 

# driver program 
if __name__=='__main__': 
  n = int(input("Enter number: "))
  print ("Following are the prime numbers smaller") 
  print ("than or equal to", n)
  SieveOfEratosthenes(n) 

'''
Following is the algorithm to find all the prime numbers less than or equal to a given 
integer n by Eratosthenes’ method:

Create a list of consecutive integers from 2 to n: (2, 3, 4, …, n).
Initially, let p equal 2, the first prime number.
Starting from p*p, count up in increments of p and mark each of these numbers greater
than or equal to p2 itself in the list. These numbers will be p(p+1), p(p+2), p(p+3), etc..

Find the first number greater than p in the list that is not marked. If there was no
such number, stop. Otherwise, let p now equal this number (which is the next prime),
and repeat from step 3.
'''