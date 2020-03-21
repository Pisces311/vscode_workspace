fun main() {
    val a = readLine()!!.toDouble()
    var tot = 0.0
    var len = 2.0
    var step = 0
    while (tot < a) {
        tot += len
        len *= 0.98
        step += 1
    }
    println(step)
}