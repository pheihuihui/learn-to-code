namespace FSharpTest

module Say =
    open System
    let hello name =
        printfn "Hello %s\t%s" name (Convert.ToString DateTime.Now)
