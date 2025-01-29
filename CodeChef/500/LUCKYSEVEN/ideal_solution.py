def lucky_letter(s):
  """
  Finds Chef's lucky letter, which is the 7th character in the given string.

  Args:
    s: The string of letters Chef saw.

  Returns:
    The lucky letter if it exists, otherwise None.
  """
  if len(s) >= 7:
    return s[6] 
  else:
    return None 