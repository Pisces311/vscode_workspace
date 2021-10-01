class Solution:
    def numUniqueEmails(self, emails: list[str]) -> int:
        ans = set()
        for email in emails:
            at = email.find('@')
            noplus = email[:at].split('+')[0]
            local = ''.join(noplus.split('.'))
            ans.add(local + email[at:])
        return len(ans)
