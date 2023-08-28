const TextField = () => {
    return(
        <input 
        type ="text"
        placeholder = " Input message"
        onChange={
            (event: React.ChangeEvent<HTMLInputElement>) => {
                console.log(event.target.value)
            }
        }
        />
    )
}
export default TextField