class Solution(object):
    def finalValueAfterOperations(self, operations):
        var = 0
        for x in operations:
            if(x[1] == '+'):
                var += 1
            else:
                var -= 1
        return var
        