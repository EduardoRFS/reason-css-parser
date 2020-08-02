open Rule.Pattern;
open Reason_css_lexer;
open Standard;

let invalid = expect(STRING("not-implemented"));
let attr_name = invalid;
let attr_fallback = invalid;
let string_token = invalid;
let ident_token = invalid;
let dimension = invalid;
let declaration_value = invalid;
let positive_integer = integer;
let function_token = invalid;
let any_value = invalid;
let hash_token = invalid;
let zero = invalid;
let custom_property_name = invalid;
let declaration_list = invalid;
let name_repeat = invalid;
let ratio = invalid;
let an_plus_b = invalid;
let declaration = invalid;
let y = invalid;
let x = invalid;
