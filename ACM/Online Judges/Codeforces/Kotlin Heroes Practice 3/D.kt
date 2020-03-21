import kotlin.math.min
import kotlin.math.max

fun main() {
    var (n, w) = readLine()!!.split(' ').map(String::toInt)
    var a = readLine()!!.split(' ').map(String::toInt)
    var min = 0
    var max = w
    var cur = 0
    for (i in 0 until n) {
        cur += a[i]
        min = max(min, -cur)
        max = min(max, w - cur)
    }
    if (min > w || max > w || min > max) println(0)
    else println(max - min + 1)
}