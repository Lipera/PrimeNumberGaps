#Installing and Loading necessary packages
install.packages("ggplot2")
install.packages("reshape2")
install.packages("Hmisc")
library(ggplot2)
library(reshape2)
library(Hmisc)

# Opening files
prime = read.csv("data/primeNumber.csv", header = FALSE, sep = " ");

#Not a beautiful manner of removing the first useless column from the files
#prime$CBO2002 = "prime"

#Saving data to access from the R markdown
save(prime, file = "data/primeNumber.Rdata")