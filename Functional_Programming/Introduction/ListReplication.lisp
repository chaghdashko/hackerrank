(defun f (n list)
    (dolist (i list)
        (dotimes (x n)
            (format t "~d~%" i))))

(defun read-list ()
    (let ((n (read *standard-input* nil)))
         (if (null n)
             nil
             (cons n (read-list)))))

(format t "~{~d~%~}" (f (read) (read-list)))
