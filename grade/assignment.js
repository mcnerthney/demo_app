function AssignmentCtrl($scope) {
    $scope.assignments = [
        {led: 10, due: 'Nov 29th', subject: 'Writer Workshop', task: 'Literary Postcards', status: 'missing' },
        {led: 9, due: 'Monday, Dec 2nd', subject: 'Science', task: 'definition homework', status: 'in-progress' },
        {led: 8, due: 'not assigned', subject: 'Writer Workshop', task: 'pet peeves', status: 'unassigned' },

        {led: 7, due: 'Monday, Dec 9nd', subject: 'History', task: '5 question video', status: 'in-progress' },
        {led: 6, due: 'Monday, Dec 9nd', subject: 'Spanish', task: 'art poster', status: 'in-progress' },


        {led: 5, due: 'Thursday, Dec 5th', subject: 'English', task: 'essay ', status: 'completed' },

        {led: 4, due: 'Wednesday, Dec 3th', subject: 'Science', task: 'bookwork', status: 'completed' },
        {led: 3, due: 'Monday, Dec 2nd', subject: 'History', task: '11/26 margin notes', status: 'completed' },
        {led: 2, due: 'Monday, Dec 2nd', subject: 'Writer Workshop', task: 'Dialog Entry', status: 'completed' },
        {led: 1, due: 'Monday, Dec 2nd', subject: 'Writer Workshop', task: 'Found Poem', status: 'completed' },
        {led: 0, due: 'Monday, Dec 2nd', subject: 'Spanish', task: '11/22 Friday Homework', status: 'completed' },
    ];
}