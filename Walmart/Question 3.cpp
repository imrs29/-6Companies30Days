//Remove Colored Pieces if Both Neighbors are the Same Color

class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int count1 = 0, count2 = 0;
        int ct = 0;
        for(int i=0; i < colors.size(); i++){
            if(colors[i] == 'A')
            ct++;
            else{
                if(ct>=3)
                count1 += ct - 2;
                ct = 0;
            }
        }
        
        if(ct >= 3)
        count1 += ct - 2;
        
        ct  =0;
        for(int i = 0; i < colors.length(); i++){
            if(colors[i] == 'B')
            ct++;
            else{
                if(ct>=3)
                count2 += ct - 2;
                ct = 0;
            }
            
        }
        
        if(ct >= 3)
        count2 += ct - 2;
        int res = count1>count2 ;
        return res;
        
        
        
    }
};
