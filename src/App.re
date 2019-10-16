[@react.component]
let make = () =>
  <div className="flex-col bg-gray-200 h-screen">
    <div className="p-8"> <Count /> </div>
    <div className="p-8 bg-gray-300"> <Todo listName="My todo list" /> </div>
  </div>;