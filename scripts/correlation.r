#Installing and Loading necessary packages
#install.packages("ggplot2")
#install.packages("reshape2")
#install.packages("Hmisc")
library(ggplot2)
library(reshape2)
library(Hmisc)

# Opening files
  #Cleaning previously generated data
  remove(prime)
  #remove(primeAux)
  
  #Reading and saving information in csv file
  prime = read.csv("../data/paradoxCorrected.csv", header = TRUE);

  correlation <- cor.test(x<-prime$PrimeGap, y<-prime$NextGap, method = c("pearson"))
  
  cor_graph <- ggplot(data = prime, aes(prime$PrimeGap, prime$NextGap)) + 
    geom_point() + labs(x = "Current Gap", y = "Next Gap") +
    geom_smooth(method = "lm")
  print(cor_graph + ggtitle("Correlation between Current Gap and Next Gap") +
          annotate("text", x = 350, y = 450, label = paste("Correlation:", correlation$estimate)))
  
  density_plot <- smoothScatter(prime$PrimeGap,prime$NextGap,
                xlab="Current Gap",ylab="Next Gap",main="Current Gap and Next Gap density")
  print(density_plot)
#Not a beautiful manner of removing the first useless column from the files
#prime$CBO2002 = "prime"
#prime["xOverlnx"] = prime$Input / log(prime$Input)

#Saving data to access from the R markdown
#save(prime, file = "data/primeNumber.Rdata")