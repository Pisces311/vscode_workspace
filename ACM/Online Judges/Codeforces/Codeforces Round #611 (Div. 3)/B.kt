import kotlin.math.min

fun main() {
    var t = readLine()!!.toInt()
    while (t-- > 0) {
        var (n, k) = readLine()!!.split(' ').map(String::toInt)
        var ans = n / k * k
        n -= n / k * k
        ans += min(n, k / 2)
        println(ans)
    }
}