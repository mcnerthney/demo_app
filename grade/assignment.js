function AssignmentCtrl($scope) {
    $scope.assignments = [
        {led: 10, due: 'Nov 29th', subject: 'Writer Workshop', task: 'Literary Postcards', status: 'completed' },
        {led: 9, due: 'Tues, Dec 10th', subject: 'Science', task: 'worksheet homework', status: 'in-progress' },
        {led: 8, due: 'Fri, Dec 13th', subject: 'Writer Workshop', task: 'pet peeves', status: 'in-progress' },
        {led: 7, due: 'Mon, Dec 9th', subject: 'History', task: '5 question video', status: 'completed' },
        {led: 6, due: 'Mon, Dec 9th', subject: 'Spanish', task: 'art poster', status: 'completed' },

        {led: 5, due: 'Thurs, Dec 5th', subject: 'English', task: 'essay ', status: 'completed' },

        {led: 4, due: 'Wed, Dec 3th', subject: 'Science', task: 'bookwork', status: 'completed' },
        {led: 3, due: 'Mon, Dec 2nd', subject: 'History', task: '11/26 margin notes', status: 'completed' },
        {led: 2, due: 'Mon, Dec 2nd', subject: 'Writer Workshop', task: 'Dialog Entry', status: 'completed' },
        {led: 1, due: 'Mon, Dec 2nd', subject: 'Writer Workshop', task: 'Found Poem', status: 'completed' },
        {led: 0, due: 'Mon, Dec 2nd', subject: 'Spanish', task: '11/22 Friday Homework', status: 'completed' },
    ];
}