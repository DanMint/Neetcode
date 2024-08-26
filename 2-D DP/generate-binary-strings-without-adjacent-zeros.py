class Solution:
    def validStrings(self, n: int) -> list[str]:
        self.combinations = [None] * (n + 1)
        self.combinations[1] = ["0", "1"]
        self.VS(2, n)
        return self.combinations[n]
    
    def VS(self, start, end):
        if start > end:
            return
        
        else: 
            prev_comb = self.combinations[start - 1]
            new_proposal = [item + "0" for item in prev_comb] + [item + "1" for item in prev_comb]

            for proposal in new_proposal[:]:
                for i in range(len(proposal) - 1):
                    if proposal[i] == '0' and proposal[i + 1] == '0':
                        new_proposal.remove(proposal)
                        break

                

            self.combinations[start] = new_proposal
            self.VS(start + 1, end)
