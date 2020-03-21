fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val questions = a.toSet().toList().sorted().take(3)
    if (questions.size < 3)
        println("-1 -1 -1")
    else
        println(questions.map { a.indexOf(it) + 1 }.joinToString(" "))
}