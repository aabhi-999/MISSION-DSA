class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        s= 1 
        for node in preorder.split(','):
            if s == 0:
                return False  
            if node == '#':
                s -= 1  
            else:
                s += 1
        return s==0
