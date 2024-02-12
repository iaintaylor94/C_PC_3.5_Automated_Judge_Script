# Programming Challenges
## Problem 3.5: Automated Judge Script[^1]
### Problem description
This program automates the judging of submittions for a programming competition. The possibilities each submittion could have are:
1. Accpted
2. Presentation Error
3. Wrong Answer

To determine the correct solution, there is a template containing the correct solution. if the submission matches the template exactly, it is evaluates to "Accepted". If the submissions digits are correct, but its characters are not, it is evaluated to "Presentation Error". If none of the above are correct, it is evaluated "Wrong Answer".

The input contains a single line with a digit (n < 100) that signifies the number of lines in the template, the next "n" lines represent the template. Another line contains the number of lines in the submission (m < 100). This format repeats itself until there is a line with a signle '0'. 

The output is a line for each test case, with the "run number#" then the status of the input.


### Example 
>**Input**
>2                                              
>The answer is: 10                                        
>The answer is: 5                                       
>2                                            
>The answer is: 10                                        
>The answer is: 5                                  
>2                                   
>The answer is: 10                                      
>The answer is: 5                                   
>2                                       
>The answer is: 10                                  
>The answer is: 15                                 
>2                                 
>The answer is: 10                                           
>The answer is: 5                                 
>2                                
>The answer is: 10                             
>The answer is: 5                                 
>3                                             
>Input Set #0: YES                                    
>Input Set #1: NO                                    
>Input Set #2: NO                              
>3                               
>Input Set #1: YES                                      
>Input Set #2: NO                                  
>Input Set #3: NO
>1
>1 0 1 0
>1
>1010
>1
>The judges are mean!
>1
>The judges are good!
>0                                                            

>**Output**
>Run #1: Accepted                                     
>Run #2: Wrong Answer                                    
>Run #3: Persentation Error                                 
>Run #4: Wrong Answer
>Run #5: Presentaion Error
>Run #6: Presentation Error                                                                         

### Problem solution
To determine if the submission is "Accepted", each character in the submission is compared to the template. If they match, the submission is accepted. To determine if the submission is "Presentation Error", both the submission and the template have all their characters removed. They are then compared as for "Accepted", if they match then the submission is presentation eror. If none of the above are true, the submission if "Wrong Answer".

### Bug Checklist
- [ ] NA

[^1]: Programming Challenges By S.Skienna and M.Revilla, page 71