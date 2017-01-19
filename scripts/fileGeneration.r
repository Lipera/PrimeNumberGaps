#Installing and Loading necessary packages
install.packages("ggplot2")
install.packages("reshape2")
install.packages("Hmisc")
library(ggplot2)
library(reshape2)
library(Hmisc)

# Opening files
  #Cleaning previously generated data
  remove(prime)
  remove(primeAux)
  
  #Reading and saving information in csv file
  prime = read.csv("data/paradoxCorrected.csv", header = TRUE);

#Not a beautiful manner of removing the first useless column from the files
#prime$CBO2002 = "prime"
prime["lnx"] = log(prime$PreviousPrime)
prime["ln2x"] = (log(prime$PreviousPrime) * log(prime$PreviousPrime))

#Saving data to access from the R markdown
save(prime, file = "data/primeNumber.Rdata")