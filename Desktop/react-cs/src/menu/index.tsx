import style from './in.module.css'
const Menu = () => {
    const bgdiv = {
        backgroundColor : "#84A7A1"
    }
    return (
    
        <div >
            <h1> Hello </h1>
         
            <ul>
                <li className= {style.bgdiv} >RedyUp</li>
                
                <li className= {style.bgexit} >Exit</li>
            </ul>
        
        </div>
    )    

}
export default Menu