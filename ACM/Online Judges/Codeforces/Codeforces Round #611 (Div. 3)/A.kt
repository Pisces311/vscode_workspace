fun main() {
    var t = readLine()!!.toInt()
    while (t-- > 0) {
        var (a, b) = readLine()!!.split(' ').map(String::toInt)
        var ans = 0
        ans += 60 - b
        a += 1
        ans += (24 - a) * 60
        println(ans)
    }
}