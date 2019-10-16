type action =
  | ToggleCompleted(string)
  | AddItem(string)
  | DeleteItem(string);

type state = {
  id: string,
  title: string,
  completed: bool,
};

module TodoItem = {
  [@react.component]
  let make = (~name, ~isComleted, ~onToggleCompleted, ~onDelete) => {
    <div className="flex my-2">
      <input
        className="mt-1 mr-3"
        type_="checkbox"
        checked=isComleted
        onChange=onToggleCompleted
      />
      <div
        className={
          "w-full " ++ (isComleted ? "line-through text-gray-600" : "")
        }>
        {ReasonReact.string(name)}
      </div>
      <button
        className="focus:outline-none text-gray-400 hover:text-red-600 font-bold"
        onClick=onDelete>
        {ReasonReact.string("X")}
      </button>
    </div>;
  };
};

[@react.component]
let make = (~listName) => {
  let (newItem, setNewItem) = React.useState(() => "");
  let (items, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | ToggleCompleted(id) =>
          List.map(
            item =>
              {
                id: item.id,
                title: item.title,
                completed: item.id === id ? !item.completed : item.completed,
              },
            state,
          )
        | AddItem(title) =>
          newItem === ""
            ? state
            : {
              setNewItem(_ => "");
              List.append(
                state,
                [
                  {
                    id: Js.Float.toString(Js.Date.now()),
                    title,
                    completed: false,
                  },
                ],
              );
            }
        | DeleteItem(id) => List.filter(item => item.id !== id, state)
        },
      [
        {id: "0", title: "Buy Milk", completed: true},
        {id: "1", title: "Learn ReasonML", completed: false},
      ],
    );

  <div className="flex-col">
    <header className="font-semibold text-xl mb-3">
      {ReasonReact.string(listName)}
    </header>
    {React.array(
       Array.of_list(
         List.map(
           item =>
             <TodoItem
               key={item.id}
               name={item.title}
               isComleted={item.completed}
               onToggleCompleted={_ => dispatch(ToggleCompleted(item.id))}
               onDelete={_ => dispatch(DeleteItem(item.id))}
             />,
           items,
         ),
       ),
     )}
    <div className="flex">
      <input className="mt-1 mr-2" type_="checkbox" disabled=true />
      <input
        className="outline-none rounded shadow-sm w-full px-2"
        type_="text"
        value=newItem
        onChange={event => ReactEvent.Form.target(event)##value->setNewItem}
        onBlur={_ => dispatch(AddItem(newItem))}
        onKeyDown={event =>
          ReactEvent.Keyboard.which(event) === 13
            ? dispatch(AddItem(newItem)) : ()
        }
      />
    </div>
  </div>;
};