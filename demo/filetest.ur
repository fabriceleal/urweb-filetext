open Filetext_FFI

fun handle r =
return <xml>
  <body>
    text:
    {[blobAsText (fileData r.Fil)]}
  </body>
</xml>

fun test () =
return <xml>
  <body>
    test
    <form>
      <upload{#Fil}/>
      <submit action={handle} />
    </form>
  </body>
</xml>
