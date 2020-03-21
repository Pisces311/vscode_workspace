import kotlin.math.max

fun main() {
    var max = 0
    var ans = 0
    for (i in 1..7) {
        var (a, b) = readLine()!!.split(' ').map(String::toInt)
        if (a + b > 8 && a + b > max) {
            max = max(max, a + b)
            ans = i
        }
    }
    println(ans)
}