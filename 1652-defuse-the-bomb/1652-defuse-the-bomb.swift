class Solution {
    func decrypt(_ code: [Int], _ k: Int) -> [Int] {
        guard k != 0 else {
            return [Int](repeating: 0, count: code.count)
        }
        
        var ans = code
        let n = code.count
        for (index, element) in code.enumerated() {
            if k > 0 {
                var total = 0
                for i in 0..<k {
                    total += code[(index + i + 1)%n]
                }
                ans[index] = total
            } else {
                var total = 0
                for i in 0..<abs(k) {
                    total += code[(index + n - i - 1)%n]
                }
                ans[index] = total
            }
        }
        return ans
    }
}