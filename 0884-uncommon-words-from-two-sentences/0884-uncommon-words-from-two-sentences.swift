class Solution {
    func uncommonFromSentences(_ s1: String, _ s2: String) -> [String] {
        let a1 = s1.components(separatedBy: " ")
        let a2 = s2.components(separatedBy: " ")
        
        var counts1: [String: Int] = [:]
        var counts2: [String: Int] = [:]
        
        a1.forEach { counts1[$0, default: 0] += 1 }
        a2.forEach { counts2[$0, default: 0] += 1 }
        
        var ans: [String] = []
        // must appear once in a1 and 0 in a2 or 1 in a2 and 0 in a1
        for a in a1 {
            if counts1[a] == 1, counts2[a] == nil {
                ans.append(a)
            }
        }
        for a in a2 {
            if counts2[a] == 1, counts1[a] == nil {
                ans.append(a)
            }
        }
        
        return ans
    }
}