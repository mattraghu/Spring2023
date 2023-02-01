import { useState } from 'react'

import Modal from './Modal'
import Backdrop from './Backdrop'

function Todo(props) {
    const [modalOpen, setModalOpen] = useState(false);

    function DeleteClicked() {
        setModalOpen(true);
        console.log('Current modalOpen state: ' + modalOpen);
    }
    function OnCancel() {
        setModalOpen(false);
        console.log('Current modalOpen state: ' + modalOpen);
    }
    function onConfirm() { 
        setModalOpen(false);
        console.log('Current modalOpen state: ' + modalOpen);
    }

    return(
        <div className="card">
            <h2> { props.text } </h2>
            <div className ="actions">
                <button className = 'btn' onClick={ DeleteClicked }>Delete</button>
            </div>
            {/* { modalOpen ? <Modal /> : null }  */}
            {modalOpen && <Modal onCancel={OnCancel} onConfirm={onConfirm}/>}
            {modalOpen && <Backdrop  onCancel={OnCancel}/>}

            {/* Create a Backdrop component */}
            {/* <Backdrop /> */}
        </div>
    );
}

export default Todo;