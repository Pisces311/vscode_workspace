import kotlin.math.min

val inf = 0x3f3f3f3f

fun main() {
    val n = readLine()!!.toInt()
    var min = inf
    for (i in 1..3) {
        var (a, b) = readLine()!!.split(' ').map(String::toInt)
        if (n % a == 0) {
            min = min(min, n / a * b)
        } else {
            min = min(min, (n / a + 1) * b)
        }
    }
    println(min)
}