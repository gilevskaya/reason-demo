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
      className={"w-full " ++ (isComleted ? "line-through text-gray-600" : "")}>
      {ReasonReact.string(name)}
    </div>
    <button
      className="focus:outline-none text-gray-400 hover:text-red-600 font-bold"
      onClick=onDelete>
      {ReasonReact.string("X")}
    </button>
  </div>;
};