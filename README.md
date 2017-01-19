# Prime Number Gap Pattern
This repository, through C code data generation and the R code data analysis, creates a dataset of prime numbers and their
gaps and we extensively analyse it trying to find a pattern.

In order to run our code, you must:

1. To generate the data, as we currently have in paradoxCorrected.csv, compile the C code in prevprime.c with the GMP 
library. That is, execute `gcc prevprime.c -lgmp`

2. Go into the scripts folder and execute it in Rstudio. This will install every package needed to generate our graphs as well 
as declaring and creating aditional collumns in the dataset for the different plots.

3. Open our Rmd file and dive into our report and graphs and try them for yourself.

#Acknowledgements
A big thanks to the professors A. Legrand and J.M. Vicent for their help and feedback as well as Marcely Zanon Boito for her 
HUGE help regarding the R code since a lot of our graphs were adapted from her work :D
