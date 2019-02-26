    l=strlen(str);
    
        printf("\nUnencrypted str = \n%s\n", str);
        
            i = 0;
                while(i < l)
                    {
                            if (str[i]!=32)  
                                        str[i] = str[i]+ offset;
                                                ++i;
                                                    }
                                                    
                                                        printf("\nEncrypted str = \n%s \nlength = %d\n", str, l);#include <stdio.h>
                                                        #include <string.h>
                                                         
                                                         void encrypt(char password[],int key)
                                                         {
                                                             unsigned int i;
                                                                 for(i=0;i<strlen(password);++i)
                                                                     {
                                                                             password[i] = password[i] - key;
                                                                                 }
                                                                                 }
                                                                                  
                                                                                  void decrypt(char password[],int key)
                                                                                  {
                                                                                      unsigned int i;
                                                                                          for(i=0;i<strlen(password);++i)
                                                                                              {
                                                                                                      password[i] = password[i] + key;
                                                                                                          }
                                                                                                          }
                                                                                                          int main()
                                                                                                          {
                                                                                                              char password[20] ;
                                                                                                                  printf("Enter the password: \n ");
                                                                                                                      scanf("%s",password);
                                                                                                                          printf("Passwrod     = %s\n",password);
                                                                                                                              encrypt(password,0xFACA);
                                                                                                                                  printf("Encrypted value = %s\n",password);
                                                                                                                                      decrypt(password,0xFACA);
                                                                                                                                          printf("Decrypted value = %s\n",password);
                                                                                                                                              return 0;
                                                                                                                                              }