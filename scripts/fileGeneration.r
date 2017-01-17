# Opening files
prime = read.csv("data/primeNumber.csv")


#Saving data to access from the R markdown
save(prime, file = "data/primeNumber.Rdata")