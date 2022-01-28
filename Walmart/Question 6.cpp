//Power of Numbers
class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       //Your code here
       if(R == 0){
           return 1;
       }
       if(R == 1){
           return N % mod;
       }
       long long res = 1;
       long long p = power(N, R/2)%mod;
       
       if(R % 2)
       res = (res*N)%mod;
       
       return (res*((p*p)%mod))%mod;
        
    }

};
