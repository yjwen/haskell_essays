(defun lisha-preamble (info)
  "Return the HTML preamble content for LisHa part."
  (let ((title "<ul> <li> Haskell漫谈集 <ul> <li> LisHa项目 </li> </ul> </li> </ul>\n")
        (navi (org-html-navigation info)))
    (concat title navi)))
