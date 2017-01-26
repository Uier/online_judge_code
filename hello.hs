fib :: Int->Int
fib 0 = 1;
fib 1 = 1;
fib n = (fib (n-1)) + (fib (n-2))

plusone :: Int->Int
plusone n = n+1

gitfirst :: [a]->a
first (x : xs) = x

my_filter :: [a]->a->a
my_filter [] n = []
my_filter (x : xs) n = 
	if x >= n then (s : (my_filter xs n))
	else my_filter xs n