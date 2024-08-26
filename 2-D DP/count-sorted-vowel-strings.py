class Solution:
    def countVowelStrings(self, n: int) -> int:
       self.arr = [None] * (n + 1)
       self.arr[0] = [1] * 5
       self.cvs(1, n , )
       return sum(self.arr[n - 1])
    
    def cvs(self, start, end):
        if start > end:
            return 
        
        else:
            self.arr[start] = [sum(self.arr[start - 1]), 
                      sum(self.arr[start - 1]) - self.arr[start - 1][0], 
                      sum(self.arr[start - 1]) - self.arr[start - 1][0] - self.arr[start - 1][1],
                      sum(self.arr[start - 1]) - self.arr[start - 1][0] - self.arr[start - 1][1] - self.arr[start - 1][2],
                      sum(self.arr[start - 1]) - self.arr[start - 1][0] - self.arr[start - 1][1] - self.arr[start - 1][2] - self.arr[start - 1][3]]
            self.cvs(start + 1, end)
