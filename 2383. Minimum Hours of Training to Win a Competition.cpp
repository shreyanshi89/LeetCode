class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n1 = 0;
        int n2 = 0;
        int sum = 0;
        
        for(int i=0;i<energy.size();i++)
                sum += energy[i];
        
        if(initialEnergy <= sum)
            n1 = (sum+1) - initialEnergy;
        
        for(int i=0;i<experience.size();i++){
            int n = 0;
            
            if(experience[i] >= initialExperience)
                n = (experience[i] - initialExperience) + 1;
        
            initialExperience += (experience[i] + n);
            n2 += n;
        }
        return n1 + n2;
    }
};
