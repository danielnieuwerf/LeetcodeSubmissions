class Solution {
    func uncommonFromSentences(_ s1: String, _ s2: String) -> [String] {
        let a1 = s1.components(separatedBy: " ")
        let a2 = s2.components(separatedBy: " ")
        
        var counts1: [String: Int] = [:]
        var counts2: [String: Int] = [:]
        
        a1.forEach { counts1[$0, default: 0] += 1 }
        a2.forEach { counts2[$0, default: 0] += 1 }
        
        var ans: [String] = []
        a1.forEach {
            if counts1[$0] == 1, counts2[$0] == nil {
                ans.append($0)
            }
        }
        a2.forEach {
            if counts2[$0] == 1, counts1[$0] == nil {
                ans.append($0)
            }
        }
        
        return ans
    }
}