const Buttonn = () => {
    const onbuttonclick = () => {
        alert("button click")
    }

    return(
         <button onClick={() => {onbuttonclick()}}> click me </button>
    )
}

export default Buttonn