import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import Menu from './menu'
import Buttonn from './assets/button'
import TextField from './texfield'




function App() {
  const [count, setCount] = useState(0)

  return (
    <>
     
      <Menu/>
      <Buttonn/>
      <TextField/>
    </>
  )
}

export default App
