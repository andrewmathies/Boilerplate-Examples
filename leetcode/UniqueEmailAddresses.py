# https://leetcode.com/problems/unique-email-addresses/

import re

class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        dict = {}
        
        for email in emails:
            beforePlusMatches = re.findall('([^+]+)', email)
            
            if len(beforePlusMatches) == 1:
                beforePlusMatches = re.findall('(.+)@', email)
            
            domainMatches = re.findall('@(.+)', email)
            
            user = beforePlusMatches[0]
            domain = domainMatches[0]
            
            user = user.replace('.', '')
            
            key = user + '@' + domain
            
            if key not in dict:
                dict[key] = True
        
        return len(dict)
            