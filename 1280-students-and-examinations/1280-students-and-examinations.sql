SELECT s.student_id,
    s.student_name,
    Subjects.subject_name,
    COUNT(e.subject_name) as attended_exams
FROM Students s
JOIN Subjects
LEFT JOIN Examinations e
ON s.student_id=e.student_id
and Subjects.subject_name=e.subject_name
GROUP BY s.student_id,Subjects.subject_name
ORDER BY s.student_id,Subjects.subject_name;