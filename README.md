# ECC-Week1_OOP_HW
Write a class that will determine the monthly payment on a home mortgage. The monthly payment with interest compounded monthly can be calculated as follows:


 monthlyPayment = (principal  x rate)/[1-(rate+1)^-term]


 rate = rate / 1200.0;
 term = term * 12.0;
 monthlyPayment = principal * rate / (1.0 – pow(rate + 1, -term));


 The class should have member functions for setting the loan amount,
 interest rate, and number of years of the loan. It should also have
 member functions for returning the monthly payment amount and the
 total amount paid to the bank at the end of the loan period,
 Implement the class in a complete program.


 Input validation: Do not accept negative numbers for any of the loan values.
