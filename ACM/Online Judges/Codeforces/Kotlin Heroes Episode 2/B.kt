import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toLong)
    var ans = 0L
    for (i in 0 until n) {
        var cur = 0L
        if (a[i] > 0)
            cur = (a[i] - 1) * n + (i + 1)
        ans = max(cur, ans)
    }
    println(ans)
}