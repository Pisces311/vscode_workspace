import kotlin.math.max

fun main() {
    var n = readLine()!!.toInt()
    var str = readLine()!!
    var ans = 0
    var cnt = 0
    for (i in 0 until n) {
        if (str[i] == 'x') ++cnt
        else {
            ans += max(cnt - 2, 0)
            cnt = 0
        }
    }
    ans += max(cnt - 2, 0)
    println(ans)
}