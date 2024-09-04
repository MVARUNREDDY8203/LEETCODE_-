class Solution:
    def fractionAddition(self, expr: str) -> str:
        if expr[0] != '-' and expr[0] != '+':
            expr = '+' + expr
        
        # denominator
        denom_str = ""
        denoms = []
        for i in expr:
            if (i == '+' or i == '-'):
                if len(denom_str) > 0:
                    denoms.append(int(denom_str))
                denom_str = ""
                continue
            if (i == '/'):
                denom_str = ""
                continue
            denom_str += i
        if len(denom_str) >= 1:
            denoms.append(int(denom_str))

        # numerator
        nume_str = ""
        numes = []
        for i in expr:
            if (i == '+' or i == '-'):
                nume_str = ""
                continue

            if (i == '/'):
                if (len(nume_str) > 0):
                    numes.append(int(nume_str))
                nume_str = ""
                continue

            nume_str += i
 
        # signs
        signs = []
        for i in expr:
            if (i == '+' or i == '-'):
                signs.append(1 if i == '+' else -1)
        
        # solving
        nume = numes[0] * signs[0]
        denom = denoms[0]
        for i in range(1, len(signs)):
            prev_denom = denom
            denom = denom * denoms[i]
            nume = nume * (denom // prev_denom) + signs[i] * numes[i] * (denom // denoms[i])
        
        hcf = math.gcd(nume, denom)
        nume = nume // hcf
        denom = denom // hcf
        
        return str(nume) + '/' + str(denom) 
